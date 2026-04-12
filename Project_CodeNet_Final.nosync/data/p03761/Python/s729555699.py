from collections import Counter
 
n = int(input())
l = []
 
for i in range(n):
    s = input()
    l.append(Counter(s))
    
cnt = l[0]
for i in range(1,n):
        cnt = cnt & l[i]
        
print("".join(sorted(cnt.elements())))