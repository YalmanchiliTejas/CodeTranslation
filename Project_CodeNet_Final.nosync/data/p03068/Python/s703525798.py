# tenka1-2019-beginnerB - *e**** ********e* *e****e* ****e**
def main():
    N, S, K = open(0).read().split()
    tgt = S[int(K) - 1]
    ans = [i if i == tgt else "*" for i in S]
    print("".join(ans))


if __name__ == "__main__":
    main()