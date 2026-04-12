n = int(input())
string = input()
k = int(input())

key = string[k-1]

index_list = [i for i,letter in enumerate(string) if letter == key]

word = ["*" for i in range(len(string))]
for elem in index_list:
	word[elem] = key

word = "".join(word)
print(word)