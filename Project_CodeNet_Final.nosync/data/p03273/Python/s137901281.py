height,width=map(int,input().split())
masu = []
for i in range(height):
    a = input()
    if "#" in a:
        masu.append(a)
N = [0]*width
for i in masu:
    for j in range(width):
        if i[j] == "." : N[j] += 1
number = []
for i in range(width):
    if N[i] != len(masu) : number.append(i)
result=[]
for i in range(len(masu)):
    a = ""
    for j in number:
        a+=masu[i][j]
    result.append(a)
for i in result:
    print(i)