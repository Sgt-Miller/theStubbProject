#include "iostream"
#include "vector"
#include "string"
#include "ctime"
using namespace std;

vector<string> key_words {"time", "chess", "ephraim", "sleep", "game","hello", "grammar"}; // understandable words
vector<string> neg {"not", "can't", "don't", "no", "hate", "detest", "loath", "mad", "moron"};
vector<string> article{"a", "an", "the"};
    vector<string> noun {"birds", "fish", "cat", "c++"};
    vector<string> verb {"rules", "fly", "cuddles", "swim"};
bool lookup(string word, vector<string> list){
	for (string x : list)
		if(word == x)
			return 1;
	return 0;
}
bool sim_sentence(){
    bool correct = true;
    // if(lookup("the", article)) cout << "found\n";
    string word;
    cin >> word;
    //cout  << "\ntook word" << word << "\n";
    //if(lookup("the", article)) cout << "found\n";

    if(!lookup(word, article)); // as cin.putback() does not work with string
        else
            cin >> word;
    if(!lookup(word, noun))
        correct = false;
   
    cin >> word;
    if(!lookup(word, verb))
        correct = false;
    return correct;
}

	void sentence(){ bool well = true;
    if(!sim_sentence()){ // Sentence without conjuction
        cout << "Incorrect sentence\n"; well = false;
    }
 
    string conj;
    cin >> conj;
    
    
    while (true){
        
        if(conj == "and" || conj == "or" || conj == "but"){
            if(!sim_sentence()){ // Sentence without conjuction
                cout << "Incorrect sentence\n"; well = false;
            }
            else 
                cin >> conj;
        }
        
        if(conj == "." && well == true){
            cout << "Correct grammar\n"; return; }
        else{
            cout << "Incorrect\n"; return;}
        
        }
        
    }

void grammar(){char temp;
	while (cin){
			
   cin >> temp;
   if(temp == 'k') break;
   else cin.putback(temp);


         sentence();
    }
}
void answer(string word){
	cout << "Bot : ";
	if(word == "hello"){
		cout << "Hello. "; // make more random greetings
		time_t now = time(0);
		  tm *ltm = localtime(&now);
		 int hour = 1 + ltm->tm_hour;
		 if(hour < 11)
		 	cout << "Good morning.";
		 else if(hour >= 11 && hour <= 4 )
		 	cout << "Good afternoon.";
		 else
		 	cout << "Good evening.";
	}
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
	if(word == "grammar"){
		cout << "Sure.\n";
		grammar();
	}
	cout << "\n";
	
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
	if(!cur_key.size()){
		cout << "Bot : ";
		if(is_pos)
			cout << "Something positive\n";
		else 
			cout << "Dont be negative.\n";

	}

	for (string x : cur_key) // improvise it to detect multiple words
		answer(x); cout << "\n";
}

int main(){
      
	while(cin){
	   	statement();
			
	}
   

}