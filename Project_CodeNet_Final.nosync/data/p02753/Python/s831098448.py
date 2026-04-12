def main():
    S = input()

    flag = False

    for i in range(1,len(S)):
        if(S[i] != S[i-1]):
            print('Yes')
            flag = True
            break

    if(not flag):
        print('No')

if __name__ == "__main__":
    main()
