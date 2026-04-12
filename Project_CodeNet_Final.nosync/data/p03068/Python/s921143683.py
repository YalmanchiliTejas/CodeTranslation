

N = int(input())
S = input()
K =  int(input())

moji = S[K-1]

result = ''
for s in S:
    if s == moji:
        result+=s
    else:
        result+='*'
print(result)