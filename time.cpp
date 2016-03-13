#include "iostream"
#include "vector"
#include "string"
#include "ctime"
using namespace std;

vector<string> key_words {"time", "chess", "ephraim", "sleep", "game"}; // understandable words
vector<string> neg {"not", "can't", "don't", "no", "hate", "detest", "loath", "mad", "moron"};
bool lookup(string word, vector<string> list){
	for (string x : list)
		if(word == x)
			return 1;
	return 0;
}

void answer(string word){

	if(word == "time"){
		time_t now = time(0);
   		char* dt = ctime(&now);
		cout << "The current local time is " << dt;
	}
	if(word == "chess"){
		cout << "Chess is a beautiful game";
	}
	if(word == "ephraim"){
		cout << "The chap who wrote this code?";
	}
	if(word == "sleep"){
		cout << "Sleep is essential";
		 time_t now = time(0);
		  tm *ltm = localtime(&now);
		 int hour = 1 + ltm->tm_hour;
		if(hour >= 22 || hour < 5)
			cout << "\nBy the way, you are supposed to be sleeping now";
	}
	if(word == "game"){
		cout << "I play a lot of Americas Army : Proving grounds";
	}


}

void statement(){
	vector<string> cur_key;
		bool is_pos = true;
	for (string temp; cin >> temp;){

		
		if(lookup(temp,neg))
		is_pos = !is_pos;

		if(temp == "." || temp == "?" || temp == "!") break;
		if(lookup(temp, key_words)){
			cur_key.push_back(temp); // push the known words
		}
		
	}
	if(is_pos)
			cout << "Something positive\n";
	else
			cout << "Dont be negative.\n";

	for (string x : cur_key) // improvise it to detect multiple words
		answer(x); cout << "\n";
}

int main(){
   
	while(cin){
	   	statement();
			cout << "\n";
	}
   

}