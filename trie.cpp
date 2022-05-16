#include <bits/stdc++.h>
using namespace std;
const int size_of_alphabet = 26;
struct node_of_Trie
{
	struct node_of_Trie *children[size_of_alphabet];
	bool isEndOfWord;
};
struct node_of_Trie *find_node(void)
{
	struct node_of_Trie *temp = new node_of_Trie;

	temp->isEndOfWord = false;

	for (int x = 0; x < size_of_alphabet; x++)
		temp->children[x] = NULL;

	return temp;
}
void insert_string(struct node_of_Trie *root_node, string str)
{
	struct node_of_Trie *temp = root_node;

	for (int x = 0; x < str.length(); x++)
	{
		int number_of_index = str[x] - 'a';
		if (!temp->children[number_of_index])
			temp->children[number_of_index] = find_node();

		temp = temp->children[number_of_index];
	}
	temp->isEndOfWord = true;
}
bool search_string(struct node_of_Trie *root_node, string str)
{
	struct node_of_Trie *temp = root_node;

	for (int x = 0; x< str.length(); x++)
	{
		int number_of_index = str[x] - 'a';
		if (!temp->children[number_of_index])
			return false;

		temp = temp->children[number_of_index];
	}

	return (temp->isEndOfWord);
}
int main()
{
	string str[] = {"then", "an", "their",
					"egg", "any", "ink",
					"king", "gun" };
	int total_size_of_string = sizeof(str)/sizeof(str[0]);
	struct node_of_Trie *root_node = find_node();
	for (int x = 0; x < total_size_of_string; x++)
    insert_string(root_node, str[x]);
	cout<<"Does ink present in this string: ";
	search_string(root_node, "ink")? cout << "Yes\n" :cout << "No\n";
	cout<<"Does eat present in this string: ";
	search_string(root_node, "eat")? cout << "Yes\n" :cout << "No\n";
	cout<<"Does king present in this string: ";
	search_string(root_node, "king")? cout << "Yes\n" :cout << "No\n";
	cout<<"Does ten present in this string: ";
	search_string(root_node, "ten")? cout << "Yes\n" :cout << "No\n";
    cout<<"Does hate present in this string: ";
    search_string(root_node, "hate")? cout << "Yes\n" :cout << "No\n";
	cout<<"Does fish present in this string: ";
	search_string(root_node, "fish")? cout << "Yes\n" :cout << "No\n";
	cout<<"Does gun present in this string: ";
	search_string(root_node, "gun")? cout << "Yes\n" :cout << "No\n";
	cout<<"Does tree present in this string: ";
	search_string(root_node, "tree")? cout << "Yes\n" :cout << "No\n";
	return 0;
}
