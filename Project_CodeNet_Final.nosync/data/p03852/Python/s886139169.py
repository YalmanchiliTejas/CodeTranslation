import re
def main():
    c = input()
    if re.match("[aiueo]",c):
        print('vowel')
    else:
        print("consonant")

if __name__ == '__main__':
    main()

