def main():

    S = input()
    for i in range(len(S)-1):
        if S[i:i+2] == "AC":
            return "Yes"
    return "No"

if __name__ == '__main__':
    print(main())