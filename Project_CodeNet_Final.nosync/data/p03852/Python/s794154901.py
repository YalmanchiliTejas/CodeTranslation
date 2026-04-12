def iroha():
    letter = input()
    vols = ["a", "i", "u", "e", "o"]

    for elm in vols:
        if elm == letter:
            print("vowel")
            return
    
    print("consonant")
            


if __name__ == "__main__":
    iroha()

