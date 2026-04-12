import numpy as np

def main():
    h, w = map(int, input().split())
    a = [input() for i in range(h)]

    for i in range(h):
        if a[i].count("#") == 0:
            a[i] = a[i].replace(".", "x")

    a = np.array([list(i) for i in a])
    a = a.transpose()
    a = ["".join(i) for i in a]

    for i in range(w):
        if a[i].count("#") == 0:
            a[i] = a[i].replace(".", "x")

    a = np.array([list(i) for i in a])
    a = a.transpose()
    a = ["".join(i) for i in a]

    for i in a:
        if i.replace("x", "") == "":
            continue
        print(i.replace("x", ""))

if __name__ == "__main__":
    main()