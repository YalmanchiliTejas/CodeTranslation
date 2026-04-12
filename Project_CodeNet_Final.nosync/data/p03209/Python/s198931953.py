N, X = map(int, input().split())
lenburger = [1]
lenputty = [1]
for i in range(N):
    lenburger.append(lenburger[i]*2+3)
    lenputty.append(lenputty[i]*2+1)
def burger(level, X):
    if level == 0:
        return 1
    elif X == 1:
        return 0
    elif X <= 1 + lenburger[level-1]:
        return burger(level-1, X-1)

    elif X == 2 + lenburger[level-1]:
        return 1 + lenputty[level-1]

    elif X <= 2 + lenburger[level-1]*2:
        return 1 + lenputty[level-1] + burger(level-1, X-2-lenburger[level-1])

    else:
        return lenputty[level]
print(burger(N, X))
