N = int(input())

H_list_str = input().split()
H_list_int = list(map(int,H_list_str))

H_Count = 1

for i in range(1,N):
    for j in range(N-1):
        if H_list_int[i] < H_list_int[j]:
            break
        else:
            if j == i-1:
                H_Count += 1
            else:
                continue

print(H_Count)