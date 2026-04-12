N = int(input())
S = input()
K = int(input())
s = ''
for i in S:
    if(i!=S[K-1]):
        s+='*'
    else:
        s+=i
print(s)
