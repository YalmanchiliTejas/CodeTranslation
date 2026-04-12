from collections import defaultdict,Counter
n=int(input())
s =[input() for i in range(n)]
dic = Counter(s[0])

for i in range(1,n):
    dic2 = Counter(s[i])
    for k,v in dic.items():

        dic[k] = min(dic[k],dic2[k])

s = ''
for k,v in dic.items():
    s+=k*v
s = sorted(s)
print(''.join(s))

            

        
            
        
    