N=int(input())
s=list(input())
for i in range(N-1):
    ss=[]
    t=list(input())
    for j in range(len(s)):
        if s[j] in t:
            ss.append(s[j])
            t.remove(s[j])
    s=ss
print("".join(sorted(s)))
    
        
    
    