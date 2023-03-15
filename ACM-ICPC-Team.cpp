#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'acmTeam' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts STRING_ARRAY topic as parameter.
 */

vector<int> acmTeam(vector<string> topic)
{
    vector<int> result;
    
    for( size_t i = 0; i < topic.size(); ++i)
    {
        for( size_t j = i+1; j < topic.size(); ++j)
        {
            int count = 0;
            for ( size_t k = 0 ; k < topic[i].size() ; ++k )
            {
                if ( topic[i][k] == '1' || topic[j][k] == '1' )
                {
                    count++;
                }   
            }
            result.push_back( count ) ;    
        }
    }
   
   int highest = *std::max_element( result.begin() , result.end() );
   int highestcount = std::count( result.begin() , result.end() , highest );
   
   return { highest , highestcount } ;    
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<string> topic(n);

    for (int i = 0; i < n; i++) {
        string topic_item;
        getline(cin, topic_item);

        topic[i] = topic_item;
    }

    vector<int> result = acmTeam(topic);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
