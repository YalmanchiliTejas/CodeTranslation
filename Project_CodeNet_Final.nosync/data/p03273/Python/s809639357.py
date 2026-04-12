a,b=map(int, input().split(" "))
arr=[]
for i in range(a):
    line=list(input())
    #for j in line;
    arr.append(line)
    #for j in range(b)
    #    arr.append()
    #line=input()
    #if "#" in line:
    #    arr.append(line)

out=[]
for i in arr:
    if "#" in i:
        out.append(i)

count={}
for i in range(len(out)):
    for j in range(len(out[0])):
        if j not in count:
            count[j]=0
        if out[i][j]=="#":
            count[j]+=1
#print(count)
#print(arr)
#print(out)

for line in out:
    result=""
    for num,i in enumerate(line):
        if count[num]!=0:
            result+=i

    if result != "":
        print(result)
