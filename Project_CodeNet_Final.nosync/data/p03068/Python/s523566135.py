word_size = int(input())
word = input()
num =  int(input())

replace_word = word[num-1]

for i in word:
    if i != replace_word:
        print("*",end="")
    else:
        print(i,end="")