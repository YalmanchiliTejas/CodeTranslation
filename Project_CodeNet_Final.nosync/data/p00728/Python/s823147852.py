array  = []
while True:
    n = int(input())
    if n == 0:
        break
    tmp_array = []
    for i in range(n):
        tmp_array.append(int(input()))
    tmp_array.sort()
    array.append(str(sum(tmp_array[1:-1])//(n-2)))

print("\r\n".join(array))

