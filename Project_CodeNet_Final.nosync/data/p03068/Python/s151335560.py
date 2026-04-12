N = int(input())
word = input()
word_list=[]
word_num = int(input())

for i in range(len(word)):
    word_list.append(word[i])
    if str(word[i]) != str(word[word_num -1]):
         word_list[i] = '*'

print("".join(list(map(str,word_list))))