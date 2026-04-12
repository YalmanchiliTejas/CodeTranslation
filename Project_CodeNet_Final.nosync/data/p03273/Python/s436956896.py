H,W = map(int,input().split())
A = []
for i in range(H):
    a = input()
    if a.count("#") >= 1:
        A.append(a)
#print(A)
B = [""]*len(A)
#print(B)
for i in range(len(A[0])):
    b = False
    for j in range(len(A)):
        #print(A[j][i])
        if A[j][i] == "#":
            b = True

    if b == True:
        for j in range(len(A)):
            B[j] += A[j][i]
        #print(1)
    #print("------------")

for k in B:
    print(k)