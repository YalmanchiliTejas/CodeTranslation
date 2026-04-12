H, W = map(int, input().split())

A_lst = []
for i in range(H):
    tmp = list(input())
    A_lst.append(tmp)

#print(A_lst)

def judge(A_lst): 
    for i in range(1, H):
        for j in range(1, W):
            if A_lst[i][j-1] == "#" and A_lst[i-1][j] == "#":
                return False
    return True

if judge(A_lst):
    print("Possible")

else:
    print("Impossible")