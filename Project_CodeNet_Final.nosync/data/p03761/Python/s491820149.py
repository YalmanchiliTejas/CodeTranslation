def Min(a,b):
    if a<b:
        return a
    return b

n=0
n=int(input())

alphabet=[[0 for i in range(26)]for i in range(n)]
for i in range(n):
    test=input()
    length=len(test)
    for j in range(length):
        k=ord(test[j])-ord('a')
        alphabet[i][k]=alphabet[i][k]+1
for i in range(26):
    minimum=50
    for j in range(n):
        minimum=Min(alphabet[j][i],minimum)
    for j in range(minimum):
        print(chr(i+ord('a')),end='')
print()
