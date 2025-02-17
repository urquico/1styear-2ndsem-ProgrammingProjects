//Bracket Matching

#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

// test input :: { [ ( < > ) ] }

//function to check matching brackets

int matchingPair(char a, char b)

{

    if(a=='{' && b=='}')

        return 1;

    else

    if(a=='[' && b==']')

        return 1;

    else

    if(a=='(' && b==')')

        return 1;

    else
    if (a=='<' && b=='>')
    return 1;

    else

return 0;

}



// Main function

int main()

{



    stack<char> st;

    string s;

    cout<<"Enter the bracket sequence\n";
    getline(cin, s);
	//cin >> s;

	remove(s.begin(), s.end(), ' ');
    s.erase(s.begin() + 8, s.end());

    for (int i = 0; i < s.length(); i++) {

        if (s[i] == '(' || s[i] == '{' || s[i] == '['||s[i]=='<') {

            st.push(s[i]);

        } else if (st.empty() || !matchingPair(st.top(),s[i])) {

            cout<<"Not a matching pair\n";

            break;

        } else {

            st.pop();

        }

    }



    if(st.empty())

        cout<<"Brackets are balanced and matched\n";



    return 0;

}