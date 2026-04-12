size = int(input())
word = input()
index = int(input())
new_word = [i if i == word[index-1] else '*' for i in word]
print("".join(new_word))