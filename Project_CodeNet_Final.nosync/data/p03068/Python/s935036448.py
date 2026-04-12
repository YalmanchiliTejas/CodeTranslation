n=int(input())
s=list(input())
k=int(input())

for i in range(n):
    if s[i] != s[k-1] :
        del s[i]
        s.insert(i,"*")
        
x=''.join(s)
        
print(x)