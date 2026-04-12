#!/usr/bin/env python3
# -*- coding: utf-8 -*-



def main():
    C = input()
    vowel = C in ("a", "e", "i", "o", "u")
    print("vowel" if vowel else "consonant")

if __name__ == "__main__": main()
