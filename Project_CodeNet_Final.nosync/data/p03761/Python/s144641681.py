n = int(input())
strs = []
inter1 = {}
for _ in range(n):
    strs.append(input())

for char in strs[0]:
    if char in inter1:
        inter1[char] +=1
    else:
        inter1[char] = 1
        
for i in range(1,n):
    inter2 = {}
    for char in strs[i]:
        if (char in inter1):
            if char in inter2:
                if inter2[char] < inter1[char]:
                    inter2[char] +=1
            else:
                inter2[char] =1 
    inter1 = inter2

inter = sorted(inter1.items())
ans = ''
for char,i in inter:
    for _ in range(i):
        ans +=char
print(ans)
        
    

