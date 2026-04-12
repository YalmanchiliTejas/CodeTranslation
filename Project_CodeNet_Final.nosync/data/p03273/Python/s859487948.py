import numpy as np

# H, W = 4, 4
# ARR = [
#     ["#", "#", ".", "#"],
#     [".", ".", ".", "."],
#     ["#", "#", ".", "#"],
#     [".", "#", ".", "#"],
# ]



H, W = map(int, input().split())
ARR = []

for i in range(H):
    ARR.append(list(input()))


def calculate(h, w, arr):
    arr = np.array(arr)
    arr = np.where(arr == ".", 0, 1)
    s = np.sum(arr, axis=1)

    p = s > 0
    m = arr[p]


    t = np.sum(m, axis=0)

    o = t > 0

    res = m[:, o]

    res = np.where(res==1,"#",".")

    for re in res:
        print("".join(re))



calculate(H, W, ARR)
