#include "iostream"
#include "vector"
#include "string"
using namespace std;


bool lookup(string word, vector<string> list){
	for (string x : list)
		if(word == x)
			return 1;
	return 0;
}

bool is_positive(vector<string>& neg) // is a positive statement
{
	bool is_pos = true;
	for (string temp; cin >> temp;)
	{	if(temp == ".") 
			break;
		if(lookup(temp,neg))
			is_pos = !is_pos; // invert is_pos, handles double negative
	}
	return is_pos;
}
int main(){
vector<string> neg {"not", "can't", "don't", "no", "hate", "detest", "loath"};

while(cin){
	if(is_positive(neg))
		cout << "That is positive";
	else
		cout << "That is not positive";
	cout << "\n";
}


cout << "\n";
}