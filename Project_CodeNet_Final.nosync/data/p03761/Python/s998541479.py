n=int(input())
h = [input() for d in range (n)]
alphabet=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
list=[]


for k in range(26):
    m=50
    for i in range (n):
         x =h[i].count(alphabet[k])
         m =min(x,m)
    list.append(alphabet[k]*m)

print(''.join(list))

