line=input().split()
h=int(line[0])
w=int(line[1])
m = []
m.append("."*(w+2))
for i in range (h):
    m.append("." + input() + ".")
m.append("."*(w+2))
works=True
for i in range (1,h+1):
    for j in range (1,w+1):
        if m[i][j]=="#":
            if m[i+1][j]=="#" and m[i][j+1]=="#":
                works=False
            if m[i-1][j]=="#" and m[i][j-1]=="#":
                works=False
if works:
    print ("Possible")
else:
    print("Impossible")
        
