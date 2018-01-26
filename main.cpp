// 3630 Cellular Automata Project
// Claire Fritzler -- 001167579
// Semester -- Fall 2015
//-----------------Algorithm------------------
// 1) Read in the necessary values
// 2) Convert the rule number to binary and the initial sequence to 0 & 1
// 3) Group the input string into its neighbours
// 4) Apply the rule to the neighbourhoods
// 5) Output the automata

#include <iostream>

using namespace std;

void convert_to_binary(int rule);
int apply_rule(int, int, int);

int binary[8];

int main()
{
    int r, n, l;
    char s[l];// = {'#','-','#','-','#','#','-','-','#','-'};
    int sequence[l];
    
    //cout << "Please enter the rule number, the number of generations, "
       //  << "and the length of the initial sequence" << endl;
   
    // 1) Read in the necessary values
    cin >> r >> n >> l;
    
   cout << "Please enter the initial sequence" << endl;
    for(int i = 0; i < l; i++)
    {
        cin >> s[i];
    }
    
    //Convert the initial sequence to 0's and 1's
    for(int i = 0; i < l; i++)
    {
        if(s[i] == '#')
            sequence[i] = 1;
        if(s[i] == '-')
            sequence[i] = 0;
    }
    
    cout << "The sequence in binary is: ";
    for(int i = 0; i < l; i++)
    {
        cout << sequence[i];
    }
    // 2) Convert the rule to binary
    convert_to_binary(r);
    // 3) Find the neighbouhoods for the input string
    int left, middle, right, newSequence;
    for(int j = 0; j < n; j++)
    {
        if(sequence[0])
        {
            left = sequence[l];
            middle = sequence[0];
            right = sequence[1];
        }
        
        if(sequence[l])
        {
            left = sequence[l-1];
            middle = sequence[l];
            right = sequence[0];
        }
        for(int i = 1; i < l; i++)
        {
            if (i == l)
            {
                left = sequence[l-1];
                middle = sequence[l];
                right = sequence[0];
                newSequence = apply_rule(left, middle, right);
                sequence[i] = newSequence;
            }
            else
            {
                left = sequence[i-1];
                middle = sequence[i];
                right = sequence[i+1];
                newSequence = apply_rule(left, middle, right);
                sequence[i] = newSequence;
            }
            // Apply the rule to the neighbours and store it in a new sequence
            cout << sequence[i];
        }
       cout << endl;
    }
}

void convert_to_binary(int rule)
{
    // First initialize all elements of the array to 0
    for(int i = 0; i < 8; i++)
        binary[i] = 0;
    
    // Use Euclidean Division to convert to binary
    int i = 8;
    while(rule != 0)
    {
        binary[i] = rule % 2;
        rule /= 2;
        i--;
    }
}

// Apply's the rule to the neighbourhood
int apply_rule(int a, int b, int c)
{
    if (a == 1 && b == 1 && c == 1)
        return binary[0];
    if (a == 1 && b == 1 && c == 0)
        return binary[1];
    if (a == 1 && b == 0 && c == 1)
        return binary[2];
    if (a == 1 && b == 0 && c == 0)
        return binary[3];
    if (a == 0 && b == 1 && c == '#')
        return binary[4];
    if (a == 0 && b == 1 && c == 0)
        return binary[5];
    if (a == 0 && b == 0 && c == 1)
        return binary[6];
    if (a == 0 && b == 0 && c == 0)
        return binary[7];
    return -1;
}

