N = int(input())
A = [0]+list(map(int, input().split(" ")))

dp_list = [{0, 0}, {0: 0, 1: A[1]}, {0: 0, 1: A[1] if A[1] > A[2] else A[2]}]

for i in range(3, N+1):
    b = (i-1)//2
    f = (i+1)//2
    dp_list.append({})
    for j in range(b, f+1):
        if j in dp_list[i-1]:
            dp_list[i][j] = dp_list[i-2][j-1]+A[i] if dp_list[i -
                                                              2][j-1]+A[i] > dp_list[i-1][j] else dp_list[i-1][j]
        else:
            dp_list[i][j] = dp_list[i-2][j-1]+A[i]

print(dp_list[-1][N//2])