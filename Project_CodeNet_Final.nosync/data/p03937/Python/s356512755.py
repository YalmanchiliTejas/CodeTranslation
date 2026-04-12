# AGC007A - Shik and Stone
def main():
    H, W, *A = open(0).read().split()
    H, W = int(H), int(W)
    flg = ("".join(A)).count("#") == H + W - 1
    print("Possible" if flg else "Impossible")


if __name__ == "__main__":
    main()