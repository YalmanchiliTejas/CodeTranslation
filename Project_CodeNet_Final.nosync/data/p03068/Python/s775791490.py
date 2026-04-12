n=int(input())
s=[a for a in input()]
k=int(input())
l=s[k-1]
for i in range(len(s)):
    if s[i] != l:
        s[i] = "*"
print(''.join(s))