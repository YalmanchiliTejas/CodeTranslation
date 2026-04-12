n = int(input())

s = [input() for i in range(n)]

sort_s = []

for i in range(n):
    sort_s.append(sorted(s[i]))
    
onaji = sort_s[0]
new = []
tmp = 0

for i in range(1,n):
    new = []
    tmp = 0
    
    for j in range(len(onaji)):
        for k in range(len(s[i])):
            #   print(i,j,tmp,k,onaji)
            if tmp+k >= len(s[i]):
                break
            if onaji[j] == sort_s[i][tmp+k]:
                new.append(onaji[j])
                tmp = tmp+k+1
                break
    #tmp = 0
    onaji = new
    #new = []
            
print(*onaji,sep="")