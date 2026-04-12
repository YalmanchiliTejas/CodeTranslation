length = int(input())

words = input()
words = list(words)

target = int(input())

char = words[target-1]

for word in words:
    if word == char:
        print(word,end='')
    else:
        print('*',end='')