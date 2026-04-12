def main():
    S = input()
    for i in range(len(S)-1):
        if S[i:i+2]=="AC":
            print("Yes")
            exit()
    print("No")
if __name__ == '__main__':
    main()