CXX=clang

all: compile

compile:
	$(CXX) -g -o 6502dasm -Wall *.c

web:
	cd web; \
	emcc ../*.c -O3 -o auto_em.js --pre-js=pre.js --memory-init-file 0 --embed-file sample/sierpinski.bin@/ -s "EXPORTED_FUNCTIONS=['_disassemble_file']" -s "EXTRA_EXPORTED_RUNTIME_METHODS=['ccall']" -s FORCE_FILESYSTEM=1; \
	cd ..

web_single:
	cd web; \
	emcc ../*.c -O3 -o embed_single.js  --pre-js=pre.js --memory-init-file 0 --embed-file sample/sierpinski.bin@/  -s "EXPORTED_FUNCTIONS=['_disassemble_file']" -s "EXTRA_EXPORTED_RUNTIME_METHODS=['ccall']" -s FORCE_FILESYSTEM=1 -s WASM=0; \
	./make_singlepage.sh \
	cd ..
	
.PHONY: web web_single