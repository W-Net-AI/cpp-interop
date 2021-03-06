#include <string>
#include <vector>

using namespace std;

#define ADD_VECTOR_HEADERS(t, tn) \
    typedef vector< t > vector_##t; \
    vector_##t * create_std_vector##tn(); \
    vector_##t * carray_to_std_vector##tn( t * a, size_t len ); \
    t * std_vector##tn##_to_carray( vector_##t * v ); \
    size_t std_vector##tn##_length( vector_##t * v); \
    void destroy_std_vector##tn( vector_##t * v); \
    void delete_std_vector##tn( vector_##t * v);

#define ADD_VECTOR_IMPL(t, tn) \
    vector_##t * create_std_vector##tn() { \
        return new vector_##t;\
    }\
    vector_##t * carray_to_std_vector##tn( t * a, size_t len ) {\
        vector_##t * v = new vector_##t;\
        for(size_t i = 0; i < len; i++) \
            v->push_back(a[i]);\
        return v;\
    }\
    t * std_vector##tn##_to_carray( vector_##t * v ) {\
        return v->data();\
    }\
    size_t std_vector##tn##_length( vector_##t * v) { \
        return v->size();\
    } \
    void destroy_std_vector##tn( vector_##t * v) { \
        v->~vector_##t();\
    }\
    void delete_std_vector##tn( vector_##t * v) { \
        delete v;\
    }\

extern "C" {
string* create_std_string();
string* cstring_to_std_string(char* s, size_t len);
const char*   std_string_to_cstring(string* s);

ADD_VECTOR_HEADERS(int, i);
ADD_VECTOR_HEADERS(float, f);
ADD_VECTOR_HEADERS(double, d);

}
