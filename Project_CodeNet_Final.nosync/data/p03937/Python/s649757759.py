h,w = map(int,input().split())

arr=[]
arr.append([".","#"]+["."]*w)
for _ in range(h):
    arr.append(["."]+list(input())+["."])
arr.append(["."]*w+["#","."])
#for row in arr:
#    print(row)

for i in range(h):
    for j in range(w):
        if arr[i+1][j+1]=='#':
            if arr[i][j+1]==arr[i+1][j] or arr[i+2][j+1]==arr[i+1][j+2]:
                print("Impossible")
                exit(0)

print("Possible")
