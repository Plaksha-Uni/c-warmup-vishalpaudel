#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cassert>

// skipping original function signature due to casting
// char* mystrstr(const char* s1, const char* s2) {
const char* mystrstr(const char* s1, const char* s2) {
	unsigned long len1=0,len2=0;
	for(unsigned long i1=0;s1[i1]!='\0';i1+=1) len1+=1;
	for(unsigned long i2=0;s2[i2]!='\0';i2+=1) len2+=1;
	// fprintf(stdout, "%8lu, %8lu\n", len1, len2);

	if(len2==0) return s1;
	if(len2>len1) return nullptr;

	for(unsigned long i1=0; i1<len1; i1+=1) {
		unsigned long i2=0;
		while(i2<len2 && (s2[i2] == s1[i1+i2])) i2+=1;
		if(i2==len2) return s1+i1;
	}

	return nullptr;
}

int main(int argc, char* argv[]) {
	assert(argc == 3);
	printf("mystrstr(\"%s\", \"%s\") = %p\n", argv[1], argv[2], mystrstr(argv[1], argv[2]));
	printf("  strstr(\"%s\", \"%s\") = %p\n", argv[1], argv[2], strstr(argv[1], argv[2]));
	assert(strstr(argv[1], argv[2]) == mystrstr(argv[1], argv[2]));
	exit(0);
}
