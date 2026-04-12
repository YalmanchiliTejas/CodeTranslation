n, x = map(int, input().split())

lengthOfBurger = [1]
numberOfPadi = [1]

for i in range(50):
    lengthOfBurger.append(1 + lengthOfBurger[-1] + 1 + lengthOfBurger[-1] + 1)
    numberOfPadi.append(numberOfPadi[-1] + 1 + numberOfPadi[-1])
A = []
def solution(k, end):
    if end == 0:
        A.append(0)
        return 0
    if end == lengthOfBurger[k]:
        A.append(numberOfPadi[k])
        return 0
    elif end == lengthOfBurger[k] + 1:
        A.append(numberOfPadi[k] + 1)
        return 0
    if end <= lengthOfBurger[k - 1] + 1:
        return solution(k - 1, end - 1)
    elif end <= lengthOfBurger[k - 1] + 2:
        return solution(k - 1, end - 1)
    elif end <= 2 * lengthOfBurger[k - 1] + 3:
        return solution(k - 1, lengthOfBurger[k - 1]+1) + solution(k - 1, end - 2 - lengthOfBurger[k - 1])
    else:
        print("NG")
        return -1

solution(n, x)

print(sum(A))