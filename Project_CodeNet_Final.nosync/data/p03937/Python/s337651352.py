
H,W = map(int,input().split())

num = 0

for i in range(H):

    A = input()

    for a in A:

        if a == "#":
            num += 1

if num == H+W-1:
    print ("Possible")
else:
    print ("Impossible")
