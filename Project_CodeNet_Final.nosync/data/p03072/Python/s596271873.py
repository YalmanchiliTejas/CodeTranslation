def convert(arr):
    H = []
    for value in arr:
        H.append(int(value))
    return H


def tellTop(i, arr):
    for index in range(i):
        if arr[index] > arr[i]:
            return False
    return True


def count(arr):
    count = 0

    for i in range(0,len(arr)):
        if tellTop(i, arr):
            count = count + 1

    return count


N = input()
arrH = input().split(' ')
N = int(N)
H = convert(arrH)

print(count(H))
