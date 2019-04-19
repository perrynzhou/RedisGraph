
MAKEFLAGS += --no-builtin-rules

.PHONY: test unit flow tck test_valgrind clean

test: flow tck

unit:
	### unit tests
	@$(MAKE) -C unit all

flow:
	### flow tests
ifeq ($(V),)
	@python -m unittest discover -b
else
	# @python -m unittest discover --verbose
	# @python -m unittest discover --verbose -p test_query_validation.py
	# @python -m unittest discover --verbose -p test_distinct.py
	# @python -m unittest discover --verbose -p test_imdb.py
	@python -m unittest discover --verbose -p test_social.py
	# @python -m unittest discover --verbose -p test_mix_labels.py
endif

tck:
	### Cypher Technology Compatibility Kit (TCK)
	@$(MAKE) -C tck

test_valgrind:
	@$(MAKE) -C unit test_valgrind

clean:
	@find . -name '*.[oad]' -type f -delete
	@find . -name '*.run' -type f -delete
	@find . -name '*.pyc' -type f -delete
