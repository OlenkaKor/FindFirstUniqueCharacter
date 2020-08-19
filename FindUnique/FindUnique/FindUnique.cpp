#include <iostream>

using namespace std;

//Just modified a little bit my first version of algorithm
//Instead of counting how many times each character in string appeared, I used a flag in this function
char findsymbol(const char *str) {
	for (int i = 0; i < strlen(str); i++) {
		bool found = true;
		for (int j = 0; j < strlen(str); j++) {
			if (str[i] == str[j] && i != j) {
				found = false;
				break;
			}
		}
		if (found == true) {
			return str[i];
		}
	}
	return -1;
}

//Second version of funnction according to the task
//Here I tried to realize function, which counts how many times each existing characters appear and writes these values in array
//I thought that complexity of this algorithm is less, so I tried to realize another algorithm for this task
char findsymbol_v2(const char *str)
{
	int *count = (int *)calloc(sizeof(int), 256);
	for (int i = 0; i < strlen(str); i++) {
		count[str[i]]++;
	}
	int pos;
	for (int i = 0; i < strlen(str); i++){
		if (count[str[i]] == 1)
		{
			pos = i;
			break;
		}
	}
	return str[pos];
}

int main()
{
	char str[] = "acdbmiomcadb";
	cout << str << "\n";
	cout << "First version: " << findsymbol(str) << "\n";
	cout << "Second version: " << findsymbol_v2(str) << "\n";
}
