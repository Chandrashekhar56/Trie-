class node_of_Trie:
	def __init__(self):
		self.child = [None]*26
		self.isEndOfWord = False
class Trie_Class:
	def __init__(self):
		self.root_node = self.find_node()

	def find_node(self):
				return node_of_Trie()
	def char_To_Index(self,ch):
		return ord(ch)-ord('a')


	def insert_string(self,str):
		temp = self.root_node
		total_size_of_string = len(str)
		for i in range(total_size_of_string):
			number_of_index = self.char_To_Index(str[i])
			if not temp.child[number_of_index]:
				temp.child[number_of_index] = self.find_node()
			temp = temp.child[number_of_index]
		temp.isEndOfWord = True

	def search_string(self, str):
		temp = self.root_node
		total_size_of_string = len(str)
		for i in range(total_size_of_string):
			number_of_index = self.char_To_Index(str[i])
			if not temp.child[number_of_index]:
				return False
			temp = temp.child[number_of_index]
		return temp.isEndOfWord

def main():
	strArray= ["then", "an", "their",
					"egg", "any", "ink",
					"king", "gun"]
	display = ["Not present in trie","Present in trie"]
	ob = Trie_Class()
	for str in strArray:
		ob.insert_string(str)

	print("{} ---- {}".format("ink",display[ob.search_string("ink")]))
	print("{} ---- {}".format("enter",display[ob.search_string("enter")]))
	print("{} ---- {}".format("king",display[ob.search_string("king")]))
	print("{} ---- {}".format("gun",display[ob.search_string("gun")]))

if __name__ == '__main__':
	main()
