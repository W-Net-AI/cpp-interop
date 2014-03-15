#include <string>
#include <vector>

using namespace std;

typedef vector<int> vector_int;
typedef vector<float> vector_float;
typedef vector<double> vector_double;

extern "C" {
string* std_create_string();
string* std_cstringToString(char* s, size_t len);
const char*   std_stringToCString(string* s);

vector_int* std_create_vector();
vector_int* std_carrayTovector(int* a, size_t len);
int*   std_vectorToCArray(vector_int* s);
size_t std_vector_length(vector_int* self);

vector_float* std_create_vectorf();
vector_float* std_carrayTovectorf(float* a, size_t len);
float*   std_vectorfToCArray(vector_float* s);
size_t std_vectorf_length(vector_float* self);

vector_double* std_create_vectord();
vector_double* std_carrayTovectord(double* a, size_t len);
double*   std_vectordToCArray(vector_double* s);
size_t std_vectord_length(vector_double* self);
}