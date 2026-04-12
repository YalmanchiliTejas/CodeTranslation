h,w=map(int,input().split())
a=[]
for i in range(h):
    arr=list(str(input()))
    if "#" in arr:a.append(arr)
for i in range(w):
    if all ([a[j][i]=="." for j in range(len(a))]):
        for k in range(len(a)):
            a[k][i]=""
for i in a:
    print("".join(i))