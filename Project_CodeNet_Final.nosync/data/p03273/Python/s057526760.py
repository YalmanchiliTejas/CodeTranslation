H, W = map(int, input().split())
arr = []
count=0
for j in range(H):
    a=list(input())
    if '#' in a:
        arr.append(a)
    else:
        count=count+1
        pass

#print(arr)
arr=list(map(list, zip(*arr)))
#print(arr)
num=[]
for j in range(W):
#    print(j, arr[j])
    if '#' in arr[j]:
        pass
    else:
        num.append(j)  

#print(num)
num.reverse()
#print(num)

for i in num:
    del arr[i]
arr=list(map(list, zip(*arr)))

for i in range(H-count):
    print("".join(arr[i]))