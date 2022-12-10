
# here i have written a phonetic_combinations function for the encoding of a word that is phonotic hashing.
# After that each word is assigned a hash code according to its phoneme so after that words which are phoneme of each other will get the same hash code and hence we can find out the phonemes.
# for this algo i am first retaining the initial letter of the string and after that encoding the consonent.
# Since First letter determines the pronunciation. after that since vowels do not contribute much so i dropped them.
# After that trucating the hash code to 7 characters. 

import sys

def phonetic_combinations(tempp):

	tempp = tempp.upper()
	encodddd = ""
	encodddd += tempp[0]
	my_dic = {"BFPV": "1", "CGJKQSXZ": "2",
				"DT": "3",
				"L": "4", "MN": "5", "R": "6",
				"AEIOUHWY": "."}

	for char in tempp[1:]:
		for key in my_dic.keys():
			if char in key:
				code = my_dic[key]
				if code != '.':
					if code != encodddd[-1]:
						encodddd += code

	encodddd = encodddd[:7].ljust(7, "0")

	return encodddd



s = sys.argv[1]  #input string
filename = sys.argv[2]  # input file

data = [l.strip() for l in open(filename)]

required = phonetic_combinations(s)

for i in data:
    if(phonetic_combinations(i)==required):
        print(f"phonetic combinations of a {s} is ", i)


# f = open(filename)  # i am assuming input file name will be "input.txt"


# print(phonetic_combinations('Moorthy'))
# print(phonetic_combinations('Moorthi'))
# print(phonetic_combinations('Moorthi'))

