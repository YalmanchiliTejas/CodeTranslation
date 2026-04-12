n = int(input())
word = list(input())
k = int(input())

ans = []

for letter in word:
    if letter == word[k-1]:
        ans.append(letter)
    else:
        ans.append('*')

print(''.join(ans))
