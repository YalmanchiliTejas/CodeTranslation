import numpy as np

def main():
    h, w = map(int,input().split())
    arr = [0 for i in range(h)]

    for i in range(h):
        arr[i] = list(input())

    arr = np.array(arr)
    yoko = []
    tate = []

    for i in range(h):
        if np.any(arr[i]=='#') == False:
            yoko.append(i)

    for i in range(w):
        if np.any(arr.transpose()[i]=="#") == False:
            tate.append(i)

    arr = np.delete(arr, yoko, 0)
    arr = np.delete(arr, tate, 1)

    for i in arr:
        print("".join(i))



if __name__ == "__main__":
        main()
