S = input()


def main():
    j = True

    for i in range(len(S)):
        if S[0] != S[i]:
            j = False
        else:
            continue

    if j:
        print("No")
    else:
        print("Yes")




if __name__ == '__main__':
    main()