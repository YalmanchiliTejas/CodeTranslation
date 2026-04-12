N = int(input())
A = [-1 for i in range(N)]

color = 1
A[0] = int(input())


def search(A, color, a):
        left = 0
        right = color - 1
        signal = 0
        while left < right:
                mid = (left + right) // 2
                if A[mid] == a - 1:
                        return mid
                        signal = 1
                elif a <= A[mid]:
                        left = mid + 1
                else:
                        right = mid
        if signal == 0:
                return left


for i in range(N - 1):
        
        a = int(input())
        num = search(A, color, a)
        if num == color - 1 and a <= A[num]:
                A[color] = a
                color += 1
        else:
                A[num] = a

print(color)