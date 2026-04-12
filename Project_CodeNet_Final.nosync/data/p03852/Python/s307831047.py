from sys import stdin, stdout
def readLine_str_list():return list(map(str, stdin.readline().split()))
def main():
    s = readLine_str_list()
    vow = ['a', 'i', 'u', 'e', 'o']
    if s[0] in vow:
        print('vowel')
    else:
        print('consonant')

if __name__ == "__main__":
    main()